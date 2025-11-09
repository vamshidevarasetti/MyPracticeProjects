import csv

def read_csv(file_path: str) -> list[dict]:
    """Read a CSV file and return its contents as a list of dictionaries."""
    with open(file_path, mode='r', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        data = [row for row in reader]
    return data

if __name__ == "__main__":
    csv_path = 'ext_files/data.csv'
    csv_data = read_csv(csv_path)
    print("CSV Data:")
    for row in csv_data:
        if row["name"].lower() == "vamshi":
            print(f"{row['name']}'s department: {row["department"]}")