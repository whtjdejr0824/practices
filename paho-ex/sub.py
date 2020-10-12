import paho.mqtt.client as mqtt
from pymongo import MongoClient
from datetime import datetime
import random

mongodb = MongoClient("mongodb://localhost:27017/")
# mongodb = MongoClient("mongodb://92.68.1.145:27017/") # 라즈베리파이일 경우 localhost 대신 IP입력
db = mongodb.iot_service

# db = MongoClient("mongodb://localhost:27017/")

# 브로커 접속 시도 결과 처리 콜백 함수
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+ str(rc))
    if rc == 0:
        client.subscribe("iot/#") # 연결 성공시 토픽 구독 신청
    else:
         print('연결 실패 : ', rc)

# 관련 토픽 메시지 수신 콜백 함수
def on_message(client, userdata, msg):
    value = float(msg.payload.decode())
    print(f" {msg.topic} {value}")
    # MongoDB에 데이터 저장하는 코드가 여기에서 이루어짐.
    doc = {
        "topic" : msg.topic,
        "value" : value,
        "reg_date" : datetime.now()
    }
    db.sersors.insert_one(doc)

# 1. MQTT 클라이언트 객체 인스턴스화
client = mqtt.Client()

# 2. 관련 이벤트에 대한 콜백 함수 등록
client.on_connect = on_connect
client.on_message = on_message

try :
    # 3. 브로커 연결
    client.connect("localhost")

    # 4. 메시지 루프 - 이벤트 발생시 해당 콜백 함수 호출됨
    client.loop_forever()
    # client.loop_start()      # 새로운 스레드를 기동해서 운영 - damon 스레드 Therad.setDaemon(True)
except Exception as err:
    print('에러 : %s'%err)

print("--- End Main Thread---")