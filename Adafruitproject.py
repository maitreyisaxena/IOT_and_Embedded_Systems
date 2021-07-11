import serial
from Adafruit_IO import *
aio=Client("your_username","your_key")





feed_name="myfeed"
try:
    feed=Feed(name=feed_name)
    aio.create_feed(feed)
    print("new feed-{} created".format(feed_name))

except:
    print("feed-{} already exists".format(feed_name))


feeds=aio.feeds()
for f in feeds:
    print(f.name, end="   ")


l=[25,34,66,40,80]

for i in l:
    data=Data(value=i)
    aio.create_data(feed_name,data)

print('data uploaded successfully')


d=aio.data(feed_name)
for i in d:
    print(i.value, end="  ")
    print(i.created_at, end="  ")
