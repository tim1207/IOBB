//
//  allPage.swift
//  newDownloadImg
//
//  Created by 林峻霆 on 2022/9/22.
//

import SwiftUI
import FirebaseStorage
import SDWebImageSwiftUI

struct allPage: View {
    @State private var fileName: [String] = []
    @State private var inputDate = Date()
    
    func listFileName(){
        let stg = Storage.storage().reference()
        var path = "image/"
        
        let formatter = DateFormatter()
        formatter.dateFormat = "MM-dd"
        path = path + formatter.string(from: inputDate)+"/"

        stg.child(path).listAll { (list, error) in
            if let error = error {
                print(error)
            } else {
                let inStorage = list.items.map({ $0.name })
                print(inStorage) // an array of file names in string format
                fileName = inStorage
                
            }
        }
    }
    
    
    var body: some View {
        VStack{
            Text("所有檔案")
                .font(.system(.title))
                .bold()
                .padding(.top,70)
            
            DatePicker(selection: $inputDate, in: ...Date(), displayedComponents: .date) {
                Text("Select a date")
            }
            .frame(width: 300, height: 2)
            .padding(15)
            .onChange(of: inputDate, perform: { value in
                 listFileName()
            })            
            
            List{
                ForEach(fileName, id: \.self) { item in
                    Text(item)
                }
            }.listStyle(.plain)
                .frame(width: 350,height: 500)


        }.onAppear(perform: listFileName)
    }
}

struct allPage_Previews: PreviewProvider {
    static var previews: some View {
        allPage()
    }
}
