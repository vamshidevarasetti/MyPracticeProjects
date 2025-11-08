import re

TS_pattern = re.compile(r'\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}.\d{3}')

def extract_timestamps(path: str) -> list:
    """Extract all timestamps from the given log file."""
    timestamps = []
    with open(path, 'r') as file:
        for line in file:
            matches = TS_pattern.findall(line)
            #timestamps.extend(matches)
            '''match = TS_pattern.search(line)
            if match:
                timestamps.append(match.group())'''
    return matches


if __name__ == "__main__":
    log_path = 'ext_files/log_file.log'  # Replace with your log file path
    ts_list = extract_timestamps(log_path)
    print("Extracted Timestamps:")
    for ts in ts_list:
        print(ts)