#!/bin/bash

rsync -chavzP --stats  --info=progress2 --exclude-from='./rsync-exc-list.txt' --ignore-existing bjenning@arrowsmith.dmz:/var/www/html-8000/sites/default/files/ files/
