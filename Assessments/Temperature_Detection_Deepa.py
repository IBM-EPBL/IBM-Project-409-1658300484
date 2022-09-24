#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import random 
import time
i=0
while(i<5):
    temperature=random.randint(20, 30)
    print("Temperature is ",temperature,"degree celsius")
    Humidity=random.randint(30, 40)
    print("Humidity is ",Humidity,"Percentage")
    if (temperature>=24):
        print("Temperature is high")
        print("Alarm on")
    else:
        print("Alarm off")
    i=i+1
    time.sleep(3)


# In[ ]:




