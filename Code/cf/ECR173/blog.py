import requests
import pprint

def get_blog(blog_id):
    url = "https://codeforces.com/api/blogEntry.view"
    params = {"blogEntryId": blog_id}
    r = requests.get(url=url, params = params)
    data = r.json()
    return data

def title(res):
    return res["title"][3:-4]

def query(l, r):
    blogs = {}
    for idx in range(l,r+1):
        print(idx)
        data = get_blog(idx)
        if(data["status"] == "OK"):
            blogs[idx] = title(data["result"])
    return blogs

l = int(input("Enter lower range: "))
r = int(input("Enter upper range: "))

p = query(l,r)
pprint.pprint(p)