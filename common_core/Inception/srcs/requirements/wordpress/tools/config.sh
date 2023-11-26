#!/bin/sh

while ! mariadb -h${MARIADB_HOST} -u${MARIADB_USER} -p${MARIADB_PASSWORD} ${MARIADB_DATABASE} >/dev/null; do
	sleep 2
done;


if [ ! -f "/var/www/html/index.html" ]; then 

wget -q https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
cp wp-cli.phar /usr/bin/wp

wp core download	--allow-root

wp config create	--dbname=${MARIADB_DATABASE} \
					--dbuser=${MARIADB_USER} \
					--dbpass=${MARIADB_PASSWORD} \
					--dbhost=${MARIADB_HOST} \
					--dbcharset="utf8" \
					--dbcollate="utf8_general_ci" \
					--allow-root

wp core install		--url=${WORDPRESS_HOST} \
					--title=${WORDPRESS_TITLE} \
					--admin_user=${WORDPRESS_ADMIN} \
					--admin_password=${WORDPRESS_ADMIN_PW} \
					--admin_email=${WORDPRESS_ADMIN_EMAIL} \
					--skip-email \
					--allow-root


wp user create		${WORDPRESS_USER} \
					${WORDPRESS_USER_EMAIL} \
					--role=author \
					--user_pass=${WORDPRESS_USER_PW} \
					--allow-root

wp plugin update	--allow-root --all

mkdir -p /run/php/

fi

/usr/sbin/php-fpm7.3 -F -R
