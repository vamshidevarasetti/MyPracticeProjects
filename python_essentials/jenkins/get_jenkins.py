import requests

JENKINS_URL = "http://localhost:8080"
USER = "vamshidevarasetti"
TOKEN = "114e24b8b60536f2537817d0ce5c18f49d"

response = requests.get(f"{JENKINS_URL}/api/json", auth=(USER, TOKEN))

print("Jenkins API Response Status Code:", response.status_code)
print("Jenkins API Response Body:", response.json())
