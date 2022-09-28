import requests
import os
def get_content():
    url = "https://www.ncsc.gov.uk/static-assets/documents/PwnedPasswordsTop100k.txt"
    response = requests.get(url)
    path = os.path.join('Passwords','password_list.txt')

    with open(path, "wb") as file:
        file.write(response.content)


get_content()