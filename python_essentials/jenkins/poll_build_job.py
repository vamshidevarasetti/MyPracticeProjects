import time
import requests

# -------------------------------
# CONFIG — UPDATE THESE VALUES
# -------------------------------
JENKINS_URL = "http://localhost:8080"
JOB_NAME = "github_autocommit"          # Change to your Jenkins job name
USER = "vamshidevarasetti"
TOKEN = "<114e24b8b60536f2537817d0ce5c18f49d>"       # Replace with your real API token
POLL_INTERVAL = 60               # seconds
# -------------------------------


def get_crumb():
    """Fetch CSRF crumb from Jenkins (if required)."""
    try:
        resp = requests.get(f"{JENKINS_URL}/crumbIssuer/api/json",
                            auth=(USER, TOKEN))
        if resp.status_code == 200:
            data = resp.json()
            return {data["crumbRequestField"]: data["crumb"]}
    except:
        pass
    return {}   # No crumb needed


def trigger_build():
    """Trigger a Jenkins job and return the queue number."""
    headers = get_crumb()

    trigger_url = f"{JENKINS_URL}/job/{JOB_NAME}/build"
    print("trigger_url:", trigger_url)
    resp = requests.post(trigger_url, auth=(USER, TOKEN), headers=headers)

    if resp.status_code not in [201, 202]:
        raise Exception(f"Failed to trigger build: {resp.status_code}")

    # Queue item URL is returned in response headers
    queue_url = resp.headers.get("Location")
    return queue_url


def get_build_number(queue_url):
    """Poll queue item until Jenkins assigns a build number."""
    while True:
        resp = requests.get(f"{queue_url}api/json", auth=(USER, TOKEN))
        data = resp.json()

        if "executable" in data:
            return data["executable"]["number"]

        print("Waiting for build to start...")
        time.sleep(3)


def poll_build_status(build_number):
    """Poll Jenkins build results every 10 seconds."""
    build_url = f"{JENKINS_URL}/job/{JOB_NAME}/{build_number}/api/json"

    while True:
        resp = requests.get(build_url, auth=(USER, TOKEN))
        info = resp.json()

        result = info.get("result")
        building = info.get("building")

        if building:
            print(f"Build #{build_number} is still running...")
        else:
            print(f"Build #{build_number} finished with result: {result}")
            return result

        time.sleep(POLL_INTERVAL)


if __name__ == "__main__":
    print("Triggering Jenkins build...")

    queue_url = trigger_build()
    print("Build queued:", queue_url)

    build_number = get_build_number(queue_url)
    print("Build started: #", build_number)

    final_result = poll_build_status(build_number)
    print("Final Build Status:", final_result)
