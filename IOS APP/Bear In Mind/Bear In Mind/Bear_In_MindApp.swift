//
//  Bear_In_MindApp.swift
//  Bear In Mind
//
//  Created by 林峻霆 on 2022/9/30.
//

import SwiftUI
import Firebase

@main
struct Bear_In_MindApp: App {
    init() {
        FirebaseApp.configure()
    }
    var body: some Scene {
        WindowGroup {
            ContentView()
        }
    }
}
