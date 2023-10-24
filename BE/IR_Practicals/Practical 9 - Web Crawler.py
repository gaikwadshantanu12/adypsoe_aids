import scrapy
class spider1(scrapy.Spider):
    name = "Wikipedia"
    start_urls = ["https://en.wikipedia.org/wiki/Battery_(electricity)"] 

    def parse(self, response):
        pass