from django import forms
import json
import requests

class KaKaoTalkForm(forms.Form):
    text = forms.CharField(label='전송할 Talk', max_length=300)
    web_url = forms.CharField(label='Web URL', max_length=300,
                        initial='IPadress')
    mobile_web_url = forms.CharField(label='Mobile Url', max_length=300,
                        initial='IPadress')
    def send_talk(self):
        talk_url = "https://kapi.kakao.com/v2/api/talk/memo/default/send"
        with open("access_token.txt", "r") as f:
            token = f.read()

        header = {"Authorization": f"Bearer {token}"}
        text_template = {
            # "object_type": "feed",
            # "content": {
            #     "title": "디저트 사진",
            #     "description": "아메리카노, 빵, 케익",
            #     "image_url": "https://www.apple.com/ac/structured-data/images/open_graph_logo.png?201812022340",
            #     "image_width": 640,
            #     "image_height": 640,
            #     "link": {
            #         "web_url": "self.cleaned_data['web_url']",
            #         "mobile_web_url": "self.cleaned_data['mobile_web_url]",
            #         "android_execution_params": "contentId=100",
            #         "ios_execution_params": "contentId=100"
            #         }
            #     },
            # "social": {
            #     "like_count": 100,
            #     "comment_count": 200,
            #     "shared_count": 300,
            #     "view_count": 400,
            #     "subscriber_count": 500
            #     },

            'object_type': 'text',
            'text': self.cleaned_data['text'],
            'link': {
                'web_url': self.cleaned_data['web_url'],
                'mobile_web_url': self.cleaned_data['mobile_web_url']
            },
            'button_title' : '카메라 보기',
            'image_url': 'Picture',
        }
        print(text_template)
        payload = {'template_object': json.dumps(text_template)}
        res = requests.post(talk_url, data=payload, headers=header)
        
        return res, self.cleaned_data['text']