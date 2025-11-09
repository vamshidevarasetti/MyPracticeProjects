import argparse

def parse_arguments():
    parser = argparse.ArgumentParser(description="simple greting script")
    parser.add_argument('--name', type=str, required=True, help='Name to greet')
    parser.add_argument('--age', type=int, required=True, help='Age of the person')
    return parser.parse_args()

if __name__ == "__main__":
    args = parse_arguments()
    print(f"Hello, {args.name}! You are {args.age} years old.")