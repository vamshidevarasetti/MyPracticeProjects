from git import Repo
from datetime import datetime
import os

def generate_change_summary(repo_path=".", output_file="change_impact_summary.txt"):
    """Generate a text file summarizing recent Git changes."""
    repo = Repo(repo_path)

    # 1️⃣ Get latest commit
    commit = repo.head.commit
    branch = repo.active_branch.name
    commit_id = commit.hexsha[:7]
    author = commit.author.name
    date = commit.committed_datetime.strftime("%Y-%m-%d %H:%M")
    message = commit.message.strip()

    # 2️⃣ Compare with previous commit
    diffs = commit.diff(commit.parents[0], create_patch=True)

    total_added = total_removed = 0
    file_changes = []

    for diff in diffs:
        added = removed = 0
        diff_text = diff.diff.decode("utf-8", errors="ignore")
        for line in diff_text.splitlines():
            if line.startswith("+") and not line.startswith("+++"):
                added += 1
            elif line.startswith("-") and not line.startswith("---"):
                removed += 1

        total_added += added
        total_removed += removed
        file_changes.append((diff.a_path or diff.b_path, added, removed))

    # 3️⃣ Write summary file
    with open(output_file, "w", encoding="utf-8") as f:
        f.write("Change Impact Summary\n")
        f.write("-" * 70 + "\n")
        f.write(f"Branch: {branch}\n")
        f.write(f"Commit ID: {commit_id}\n")
        f.write(f"Author: {author}\n")
        f.write(f"Date: {date}\n")
        f.write(f"Message: {message}\n\n")

        f.write("Files Changed:\n")
        for file_path, added, removed in file_changes:
            f.write(f"  - {file_path} (+{added}, -{removed})\n")

        f.write("\nSummary:\n")
        f.write(f"  Total Files Changed: {len(file_changes)}\n")
        f.write(f"  Total Lines Added: {total_added}\n")
        f.write(f"  Total Lines Removed: {total_removed}\n")

    print(f"✅ Change impact summary generated: {os.path.abspath(output_file)}")


if __name__ == "__main__":
    generate_change_summary()
