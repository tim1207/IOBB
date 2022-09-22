//
//  ContentView.swift
//  newDownloadImg
//
//  Created by 林峻霆 on 2022/9/21.
//

import SwiftUI
import FirebaseStorage
import SDWebImageSwiftUI
struct ContentView: View {
    
    var body: some View {
        TabView{
            homePage()
                .tabItem{
                    Label("首頁", systemImage: "house")
                }
            allPage()
                .tabItem{
                    Label("所有檔案名稱", systemImage: "list.bullet")
                }
        }
    }
  }
  

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
