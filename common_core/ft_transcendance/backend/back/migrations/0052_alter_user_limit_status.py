# Generated by Django 3.2.25 on 2024-03-11 16:16

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('back', '0051_alter_user_limit_status'),
    ]

    operations = [
        migrations.AlterField(
            model_name='user',
            name='limit_status',
            field=models.CharField(default='16:16', max_length=20),
        ),
    ]
