import random
import time

while True:
    temp = random.randint(30, 100)
    print(f"Current Temperature : {temp}")
    if temp > 60:
        print(f"Alert! High Temperature - {temp}!!!")
    time.sleep(1)
