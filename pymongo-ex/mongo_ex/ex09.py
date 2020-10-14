from pymongo import MongoClient
from bson.objectid import ObjectId
from datetime import datetime
import random

db_client = MongoClient("mongodb://localhost:27017/")

iot_db = db_client['iot_service']
sensors_col = iot_db['sensors']

query = {"value":{"$lt":55.1}}
# query = { "_id" : ObjectId("#")} # 데이터 한개를 삭제할때 이방법이 더 일반적
# sensors_col.delete_one(query)
sensors_col.delete_many(query)

sensor_values = sensors_col.find(query)
for x in sensor_values:
    print(x)