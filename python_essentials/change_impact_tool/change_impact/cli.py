from git import Repo
from datetime import datetime
import argparse
import os
import sys

def generate_change_summary(repo_path=".", output_file="change_impact_summary.txt"):
    """Generate a text file summarizing recent Git changes."""
    repo = Repo(repo_path)

    commit = repo.head.commit
    branch = repo.active_branch.name
    commit_id = commit.hexsha[:7]
    author = commit.author.name
    date = commit.committed_datetime.strftime("%Y-%m-%d %H:%M")
    message = commit.message.strip()

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

    print(f"✅ Change impact summary generated at: {os.path.abspath(output_file)}")


def main():
    parser = argparse.ArgumentParser(
        prog="change-impact",
        description="Generate a Change Impact Summary from the latest Git commit."
    )

    parser.add_argument(
        "--repo", type=str, default=".",
        help="Path to the Git repository (default: current directory)"
    )
    parser.add_argument(
        "--output", type=str, default="change_impact_summary.txt",
        help="Path to save the generated summary file (default: change_impact_summary.txt)"
    )

    args = parser.parse_args()

    try:
        generate_change_summary(args.repo, args.output)
    except Exception as e:
        print(f"❌ Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()