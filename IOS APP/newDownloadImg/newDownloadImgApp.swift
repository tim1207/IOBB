//
//  newDownloadImgApp.swift
//  newDownloadImg
//
//  Created by 林峻霆 on 2022/9/21.
//

import SwiftUI
import Firebase

@main
struct newDownloadImgApp: App {
    init() {
            FirebaseApp.configure()
        }
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}
