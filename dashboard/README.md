## [dashboard](https://github.com/qitas/web4Pi) 

#### qitas@qitas.cn

## [项目来源](https://maker.quwj.com/project/10) 

dashboard管理窗口，通过网页进行管理

* 安装 Nginx 和 PHP

```

sudo apt update
sudo apt install nginx php7.0-fpm php7.0-cli php7.0-curl php7.0-gd php7.0-mcrypt php7.0-cgi
sudo service nginx start
sudo service php7.0-fpm restart

```

* 通过 http://树莓派IP  访问到Nginx的默认页。Nginx的根目录在/var/www/html。

```

sudo vi /etc/nginx/sites-available/default

#将其中的内容

location / {
                # First attempt to serve request as file, then
                # as directory, then fall back to displaying a 404.
                try_files $uri $uri/ =404;
        }

#替换为
location / {
index  index.html index.htm index.php default.html default.htm default.php;
}
 
location ~\.php$ {
fastcgi_pass unix:/run/php/php7.0-fpm.sock;
#fastcgi_pass 127.0.0.1:9000;
fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
include fastcgi_params;
}

#重启 Nginx 
sudo service nginx restart

```

### 锻造最美之器

