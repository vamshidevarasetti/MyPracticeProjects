from collections import Counter
from datetime import datetime

LOG_FILE = "app.log"

today = datetime.now().strftime("%Y-%m-%d")
errors = []

with open(LOG_FILE) as f:
    for line in f:
        if line.startswith(today) and "ERROR" in line:
            # remove date & time
            message = " ".join(line.split()[2:])
            errors.append(message)

if not errors:
    print("✅ No ERROR logs found today.")
    exit(0)

counter = Counter(errors)

print(f"\n📅 ERROR Summary for {today}")
print("-" * 40)

for msg, count in counter.most_common():
    print(f"{count:1}x {msg}")

print("-" * 40)
print(f"❗ Total ERROR count: {sum(counter.values())}")
