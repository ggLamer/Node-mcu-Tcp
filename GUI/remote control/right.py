import requests
while True:
    
    print(requests.get("http://192.168.0.127/dist").text)