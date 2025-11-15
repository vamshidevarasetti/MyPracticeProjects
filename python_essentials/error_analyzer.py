import re
import json
import argparse
from typing import List, Dict
from collections import Counter

def load_config(config_path: str) -> Dict:
    """Load the error analysis configuration from a JSON file."""
    with open(config_path, 'r') as file:
        config = json.load(file)
    return config

def extract_error_messages(log_path: str, error_patterns: str) -> List[str]:
    """Extract error messages from the log file based on provided patterns."""
    error_messages = []
    compiled_patterns = re.compile(error_patterns, re.IGNORECASE)
    
    with open(log_path, 'r') as file:
        for line in file:
            match = compiled_patterns.search(line)
            if match:
                if match.groups():
                    msg = match.group(1).strip(" :-")
                else:
                    msg = line.strip(" :-")
                error_messages.append(msg)
                break
    return error_messages

def print_top_errors(error_messages: List[str], top_n: int):
    """Print the top N most common error messages."""
    counter = Counter(error_messages)
    most_common = counter.most_common(top_n)
    
    print(f"\nTop {top_n} repeating error patterns:\n" + "-"*50)
    for message, count in most_common:
        print(f"{count:>2} occurrences: {message}")
        
        
def main():
    parser = argparse.ArgumentParser(description="Analyze log files for error patterns.")
    parser.add_argument('--config_path', type=str, help="Path to the error analysis configuration JSON file.")
    parser.add_argument('--top_n', type=int, default=5, help="Number of top error patterns to display.")
    
    args = parser.parse_args()
    
    config = load_config(args.config_path)
    log_path = config.get("log_file", "")
    error_patterns = config.get("error_pattern", "")
    
    print(f"Analyzing log file: {log_path}")
    
    error_messages = extract_error_messages(log_path, error_patterns)
    print_top_errors(error_messages, args.top_n)
    
    
if __name__ == "__main__":
    main()