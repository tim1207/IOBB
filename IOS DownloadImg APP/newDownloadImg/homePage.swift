//
//  homePage.swift
//  newDownloadImg
//
//  Created by 林峻霆 on 2022/9/22.
//

import SwiftUI
import FirebaseStorage
import SDWebImageSwiftUI

struct homePage: View {
    @State private var imageURL = URL(string: "https://firebasestorage.googleapis.com/v0/b/iobb-43250.appspot.com/o/image%2F%E6%88%AA%E5%9C%96%202022-09-21%20%E4%B8%8B%E5%8D%8810.00.18.png?alt=media&token=ad4d7aa4-e451-448f-9ce1-2cb35343f832")
    @State private var name: String = ""
    @State private var nowPhoto: String = "截圖 2022-09-21 下午10.00.18.png"
    
    
    func loadImageFromFirebase(name: String) {
         let storage = Storage.storage().reference(withPath: name)
         storage.downloadURL { (url, error) in
             if error != nil {
                 print((error?.localizedDescription)!)
                 return
         }
         print("Download success")
             imageURL = url!
             nowPhoto = name
             
     }
    }

    
    var body: some View {
        VStack{

            TextField(
                "Enter name",
                text: $name
            )
            .autocapitalization(.none)
            .font(.system(size: 18))
            .frame(width: 300, height: 20)
            .foregroundColor(.blue)
            .padding()

            Button{
                loadImageFromFirebase(name: name)
            }label: {
                Text("Get photo Link ")
                    .font(.system(size: 20))
                    .frame(width: 250, height: 10)
                    .padding()
                    .overlay(
                        RoundedRectangle(cornerRadius: 15)
                            .stroke(Color.blue, lineWidth: 3)
                    )

            }
            Divider()
                .frame(width: 300, height: 2)
                .overlay(.black)
                .padding(.bottom,15)
            VStack{
                Text("Now photo name is")
                    .font(.system(size: 20))
                    .padding(.bottom,15)
                Text("\(nowPhoto)")
                    .padding(.bottom,15)
            }

            Link("Go to Link", destination: imageURL!)
                .font(.system(size: 20))
                .frame(width: 250, height: 10)
                .padding()
                .overlay(
                    RoundedRectangle(cornerRadius: 15)
                        .stroke(Color.blue, lineWidth: 3)
                )


        }
  }
}

struct homePage_Previews: PreviewProvider {
    static var previews: some View {
        homePage()
    }
}
