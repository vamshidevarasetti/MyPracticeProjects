import json

def read_json_file(path: str) -> dict:
    """Read a JSON file and return its contents as a dictionary."""
    with open(path, 'r') as f:
        data = json.load(f)
    return data

if __name__ == "__main__":
    json_path = 'ext_files/config.json'  # Replace with your JSON file path
    json_data = read_json_file(json_path)
    print("JSON Data:")
    #print(json_data)
    print("App Name:", json_data["app_name"])