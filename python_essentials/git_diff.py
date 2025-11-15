import subprocess

def get_git_diff():
    result = subprocess.run(
        ["git", "diff", "HEAD"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    if result.returncode != 0:
        print("❌ Error:", result.stderr.strip())
        return ""
    return result.stdout.strip()

def count_diff_lines(diff: str) -> int:
    return len(diff.splitlines())

def count_diff_changes(diff: str) -> int:
    additions = sum(1 for line in diff.splitlines() if line.startswith('+') and not line.startswith('+++'))
    deletions = sum(1 for line in diff.splitlines() if line.startswith('-') and not line.startswith('---'))
    return additions , deletions

def main():
    diff = get_git_diff()
    if diff:
        print("\nGit Diff between last two commits:\n" + "-"*50)
        additions , deletions = count_diff_changes(diff)
        print(f"Total lines changed: {count_diff_lines(diff)}")
        print(f"Lines added: {additions}") 
        print(f"Lines deleted: {deletions}")
        print("\nDiff Details:\n" + "-"*50)
    else:
        print("No differences found or not a git repository.")
        

if __name__ == "__main__":
    main()
    
    
    