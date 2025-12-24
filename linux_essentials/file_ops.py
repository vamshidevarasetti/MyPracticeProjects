import os
import shutil
import stat

BASE = "file_ops"

def setup_directories():
    folders = ["input", "output", "logs"]
    for folder in folders:
        path = os.path.join(BASE, folder)
        os.makedirs(path, exist_ok=True)
        print(f"created dir path : {path}")


def create_sample_files():
    input_file = os.path.join(BASE, "input", "data.txt")
    with open(input_file, "w") as f:
        f.write("Hello, this is a sample input file.\n")
    print(f"input file created : {input_file}")

def read_file(file_path):
    with open(file_path, "r") as f:
        print(f.read())

def copy_file():
    src = os.path.join(BASE, "input", "data.txt")
    dest = os.path.join(BASE, "output", "copy_data.txt")
    print("SRC exists:", os.path.exists(src))
    print("DEST DIR exists:", os.path.exists(dest))
    shutil.copy(src, dest)
    print(f"copied {src} -> {dest}")

def change_permissions():
    filepath = os.path.join(BASE, "output", "copy_data.txt")
    os.chmod(filepath, stat.S_IREAD)
    print(f"set read only permission on {filepath}")
    os.chmod(filepath, stat.S_IWRITE)
    print(f"restored write permission on {filepath}")

def remove_files():
    if os.path.exists(BASE):
        shutil.rmtree(BASE)
        print("Deleted entire file ops folder")



def main():
    setup_directories()
    create_sample_files()
    read_file(os.path.join(BASE, "input", "data.txt"))
    copy_file()
    change_permissions()
    remove_files()

if __name__ == "__main__":
    main()