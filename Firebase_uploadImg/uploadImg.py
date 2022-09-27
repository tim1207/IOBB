from firebase_admin import credentials, initialize_app, storage
# Init firebase with your credentials
cred = credentials.Certificate("Firebase_uploadImg/iobb-43250-firebase-adminsdk-zfigz-a8e63d131a.json")
initialize_app(cred, {'storageBucket': 'iobb-43250.appspot.com'})

# Put your local file path 
fileName = "Firebase_uploadImg/截圖 2022-09-27 下午8.26.54.png"
bucket = storage.bucket()
blob = bucket.blob(fileName)
blob.upload_from_filename(fileName)

# Opt : if you want to make public access from the URL
blob.make_public()

print("your file url", blob.public_url)



