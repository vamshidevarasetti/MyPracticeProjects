import os
import requests

# ---------------------------------------
# UPDATE THESE VALUES
# ---------------------------------------
JENKINS_URL = "http://localhost:8080"
JOB_NAME = "github_autocommit"  # <-- your job name
BUILD_NUMBER = "lastSuccessfulBuild"  # or "lastBuild" or "42"
USER = "vamshidevarasetti"
API_TOKEN = "114e24b8b60536f2537817d0ce5c18f49d"
DOWNLOAD_DIR = "artifacts"   # folder to save artifacts
# ---------------------------------------


def download_artifacts():
    # Make download folder
    os.makedirs(DOWNLOAD_DIR, exist_ok=True)

    # Artifact metadata URL
    api_url = f"{JENKINS_URL}/job/{JOB_NAME}/{BUILD_NUMBER}/api/json"

    # GET build metadata (list of artifacts)
    print("[INFO] Fetching artifact metadata...")
    resp = requests.get(api_url, auth=(USER, API_TOKEN))

    if resp.status_code != 200:
        print(f"[ERROR] Failed to get build info: {resp.status_code}")
        print(resp.text)
        return

    data = resp.json()

    # Check if artifacts exist
    if "artifacts" not in data or not data["artifacts"]:
        print("[INFO] No artifacts found in this build.")
        return

    print(f"[INFO] Found {len(data['artifacts'])} artifacts")

    # Download each artifact
    for artifact in data["artifacts"]:
        file_name = artifact["fileName"]
        relative_path = artifact["relativePath"]

        # Artifact download URL
        download_url = f"{JENKINS_URL}/job/{JOB_NAME}/{BUILD_NUMBER}/artifact/{relative_path}"

        print(f"[INFO] Downloading: {file_name}")

        # GET the artifact file
        r = requests.get(download_url, auth=(USER, API_TOKEN))

        if r.status_code == 200:
            save_path = os.path.join(DOWNLOAD_DIR, file_name)
            with open(save_path, "wb") as f:
                f.write(r.content)
            print(f"[SUCCESS] Saved to {save_path}")
        else:
            print(f"[ERROR] Failed to download {file_name}: Status {r.status_code}")


if __name__ == "__main__":
    download_artifacts()
