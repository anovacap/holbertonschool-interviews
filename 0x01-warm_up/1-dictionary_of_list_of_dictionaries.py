#!/usr/bin/python3
"""Using a REST API for a given employee ID, returns
information about his / her TODO list progress """
import json
import requests
import sys


def main():
    url_todo = "https://jsonplaceholder.typicode.com/todos"
    url_user = "https://jsonplaceholder.typicode.com/users"
    todos = requests.get(url_todo)
    users = requests.get(url_user)
    js_todo = todos.json()
    js_user = users.json()
    with open("todo_all_employees.json", "w") as f:
        js_fmt = {}
        for x in js_user:
            task_l = []
            for y in js_todo:
                if y.get('userId') == x.get('id'):
                    task_l.append({'username': x.get('username'),
                                   'task': y.get('title'),
                                   'completed': y.get('completed')})
            js_fmt[x.get('id')] = task_l
        f.write(json.dumps(js_fmt))

if __name__ == "__main__":
    main()
