# Generated by Django 3.2.24 on 2024-03-03 20:08

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('back', '0023_alter_user_token_jwt'),
    ]

    operations = [
        migrations.CreateModel(
            name='Friendship',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('from_f', models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='from_f', to='back.user')),
                ('to_f', models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.CASCADE, related_name='to_f', to='back.user')),
            ],
        ),
        migrations.AddField(
            model_name='user',
            name='friends',
            field=models.ManyToManyField(through='back.Friendship', to='back.User'),
        ),
    ]
