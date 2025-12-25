import psutil
import time
import logging

PROCESS_NAME = "chrome"
CHECK_INTERVAL = 5

logging.basicConfig(filename="process_monitor.log", level=logging.INFO,
                    format="%(asctime)s - %(levelname)s - %(message)s")

def find_process_by_name(name):
    """Check if there is any running process that contains the given name."""
    result = []
    for proc in psutil.process_iter(['pid','name']):
        if proc.info['name'] == name and name.lower() in proc.info['name'].lower():
            result.append(proc)
    return result


def monitor_process():
    logging.info(f"Starting process monitor for '{PROCESS_NAME}'")
    try:
        while True:
            processes = find_process_by_name(PROCESS_NAME)
            if not processes:
                logging.info(f"No process named '{PROCESS_NAME}' found.")
            else:
                for proc in processes:
                    cpu = proc.cpu_percent(interval=1)
                    mem = proc.memory_percent()
                    logging.info(f"PID={proc.pid} CPU={cpu}% MEM={mem:.2f}%Status=OK")
                    print(f"PID={proc.pid} CPU={cpu}% MEM={mem:.2f}% Status=OK")
            time.sleep(CHECK_INTERVAL)
    except KeyboardInterrupt:
        logging.info("Process monitor stopped by user.")

if __name__ == "__main__":
    monitor_process()
