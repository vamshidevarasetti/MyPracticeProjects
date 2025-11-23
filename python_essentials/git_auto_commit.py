from git import Repo, GitCommandError, InvalidGitRepositoryError, NoSuchPathError
from datetime import datetime
import os
import sys

def auto_commit(repo_path: str, branch_name: str = "master"):
    """Stage, commit, and push all local changes to the given branch."""
    try:
        # 1️⃣ Try opening the repository
        repo = Repo(repo_path)
        if repo.bare:
            print(f"❌ '{repo_path}' is an empty repository.")
            return

    except (InvalidGitRepositoryError, NoSuchPathError):
        print(f"❌ Error: '{repo_path}' is not a valid Git repository.")
        return
    
    try:
        # 2️⃣ Ensure we are on the correct branch
        if repo.active_branch.name != branch_name:
            print(f"🔀 Switching to branch '{branch_name}'...")
            repo.git.checkout(branch_name)

        # 3️⃣ Stage all changes (new, modified, deleted files)
        print("📦 Staging all changes...")
        repo.git.add(A=True)   # equivalent to 'git add -A'

        # 4️⃣ Check if there is anything to commit
        if not repo.is_dirty(untracked_files=True):
            print("✅ No new changes to commit.")
            return

        # 5️⃣ Create a commit message with timestamp
        commit_message = f"Auto-commit: updates on {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}"
        print(f"📝 Committing with message: {commit_message}")
        repo.index.commit(commit_message)

        # 6️⃣ Push to remote
        print("⬆️ Pushing to remote repository...")
        origin = repo.remote(name='origin')
        push_info = origin.push(branch_name)

        # 7️⃣ Confirm success
        for info in push_info:
            if info.flags & info.ERROR:
                print(f"❌ Push failed: {info.summary}")
            else:
                print(f"✅ Push successful: {info.summary}")

    except GitCommandError as e:
        print(f"❌ Git error: {e}")
    except Exception as e:
        print(f"❌ Unexpected error: {e}")


if __name__ == "__main__":
    # Default to current directory if no path provided
    repo_path = sys.argv[1] if len(sys.argv) > 1 else os.getcwd()
    print(f"Running auto-commit for repository: {repo_path}")
    auto_commit(repo_path, branch_name="master")
    print("Auto-commit process completed.")