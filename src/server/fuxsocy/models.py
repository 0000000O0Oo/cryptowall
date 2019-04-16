from django.db import models
from django.utils import timezone

class Victim(models.Model):
    """ Contains victim's infomration """
    id = models.CharField(max_length=20, primary_key=True)
    iv = models.CharField(max_length=16)
    key = models.CharField(max_length=32)
    ip = models.CharField(max_length=16, null=True, blank=True)
    paid = models.BooleanField()

    create_time = models.DateTimeField(editable=False)
    update_time = models.DateTimeField()

    def save(self, *args, **kwargs):
        if not self.create_time:
            self.create_time = timezone.now()
        self.update_time = timezone.now()
        super().save(*args, **kwargs)

    def __str__(self):
        return "[{paid}] <id: {id}> iv:{iv} key:{key}".format(
            paid="v" if self.paid else " ", id=self.id, iv=self.iv, key=self.key)
