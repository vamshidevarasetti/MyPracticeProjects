import requests

JENKINS_URL = "http://localhost:8080"
JOB_NAME = "BuildApp"

USER = "vamshidevarasetty"
TOKEN = "<YOUR_API_TOKEN>"

params = {
    "ENV": "dev"
}

trigger_url = f"{JENKINS_URL}/job/{JOB_NAME}/buildWithParameters"

response = requests.post(trigger_url, params=params, auth=(USER, TOKEN))

print("Status:", response.status_code)
print("Triggered job with params:", params)
