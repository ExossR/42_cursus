# Generated by Django 3.2.23 on 2024-02-22 15:53

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('back', '0007_user_avatar_id'),
    ]

    operations = [
        migrations.RenameField(
            model_name='user',
            old_name='avatar_id',
            new_name='avatar',
        ),
    ]
