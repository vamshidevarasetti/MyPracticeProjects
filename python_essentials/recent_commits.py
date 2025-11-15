from datetime import datetime, timedelta
import subprocess


def get_recent_commits(hours: int = 24) -> str:
    """Get recent git commits from the last specified hours."""
    since_time = (datetime.now() - timedelta(hours=hours)).strftime('%Y-%m-%d %H:%M:%S')
    # Run the git log command
    result = subprocess.run(
        ["git", "log", f'--since="{since_time}"', '--pretty=format:%h | %an | %ad | %s', '--date=short'],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    if result.returncode != 0:
        print("❌ Error:", result.stderr.strip())
        print("Make sure this script is run inside a Git repository.")
        return []

    commits = result.stdout.strip().splitlines()
    return commits


def main():
    commits = get_recent_commits(500)
    if commits:
        print("\nRecent Git Commits (last 24 hours):\n" + "-"*50)
        for commit in commits:
            print(commit)
    else:
        print("No recent commits found.")
        
if __name__ == "__main__":
    main()
    