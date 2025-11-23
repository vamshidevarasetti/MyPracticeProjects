import requests

JENKINS_URL = "http://localhost:8080"
USER = "vamshidevarasetti"
TOKEN = "114e24b8b60536f2537817d0ce5c18f49d"
JOB_NAME = "Helloworld"

trigger_url = f"{JENKINS_URL}/job/{JOB_NAME}/build"

response = requests.post(trigger_url, auth=(USER, TOKEN))

print("Status:", response.status_code)
print("Triggered job:", JOB_NAME)
