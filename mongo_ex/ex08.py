from pymongo import MongoClient
from datetime import datetime
import random

db_client = MongoClient("mongodb://localhost:27017/")

iot_db = db_client['iot_service']
sensors_col = iot_db['sensors']

query = {"value": {"$gt":24.1}}
projection = { "_id" : 0, "topic":1, "value":1}
# projection = { "_id" : 0, "reg_date":0}
newvalues = {"$set": { "reg_date": datetime.now()}}
sensors_col.update_many(query, newvalues)
slist = sensors_col.find(query, projection).sort("reg_date") # .sort("value", -1)

for x in slist:
    print(x)