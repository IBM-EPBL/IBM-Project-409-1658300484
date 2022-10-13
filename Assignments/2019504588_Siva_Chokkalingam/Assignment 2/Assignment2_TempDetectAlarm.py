import random
temp_threshold = 30
humid_threshold = 40
var = 0
while True:
  t = random.randint(0,60)
  h = random.randint(10,90)
  print("temp: ", t, "humid: ", h ,end=" ")
  if (random.randint(0,60) > temp_threshold) and (random.randint(10,90)):
    print("Alarm detected")
  print()
