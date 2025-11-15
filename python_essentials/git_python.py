from git import Repo

repo = Repo('.')

#for commit in list(repo.iter_commits('HEAD', max_count=5)):
 #   print(f"Commit: {commit.hexsha}\nAuthor: {commit.author.name}\nDate: {commit.committed_datetime}\nMessage: {commit.message}\n{'-'*50}")
    
    
commit = repo.head.commit
print("commit id:", commit.hexsha)
print("author:", commit.author.name)
print("date:", commit.committed_datetime)
print("message:", commit.message)
print("commit diff", commit.diff() )
print("repo branch:", repo.active_branch.name)
print("files changed:")
for diff in commit.diff(None):
    print(f"- {diff.a_path}")