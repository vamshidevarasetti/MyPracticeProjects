def count_errors(path: str) -> int:
    """Count the number of lines containing the word 'error' in a file."""
    error_count = 0
    with open(path, 'r') as file:
        for line in file:
            if 'error' in line.lower():
                error_count += 1
                idx = line.lower().index('error')
                print(f"Error found: {line[idx + len("error"):].strip(" -:")} at index {idx}")
    return error_count


if __name__ == "__main__":
    log_path = 'ext_files/log_file.log'  # Replace with your log file path
    errors = count_errors(log_path)
    print(f"Number of error lines: {errors}")