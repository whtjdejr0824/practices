import requests
import json
kakao_speech_url = "https://kakaoi-newtone-openapi.kakao.com/v1/recognize"

rest_api_key = 'c90d79b841454ea08b11a3a3bbf873d8'

headers = {
    "Content-Type": "application/octet-stream",
     "X-DSS-Service": "DICTATION",
     "Authorization": "KakaoAK " + rest_api_key,
}

def dictation(audio):
    res = requests.post(kakao_speech_url, headers=headers, data=audio)

    result_json_string = res.text[
        res.text.index('{"type":"finalResult"'):res.text.rindex('}')+1
    ]

    result = json.loads(result_json_string)
    return result['value']

if __name__ == "__main__":
    with open('heykakao.wav', 'rb') as fp:
        audio = fp.read()
        result = dictation(audio)
        print(result)