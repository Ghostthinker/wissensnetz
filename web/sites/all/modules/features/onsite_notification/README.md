Salto notifications
===================

Salto notifications are events that users can subscribe to and determine channel. Channels are

* email
* onsite
* disabled

Notifications are defined via an info hook and can have multiple contexts like *node*, *comment*, or any other entity. Users can set there notification channel in the message settings.

email notification
------------------
Email Notifications are sent directly. There is no grouping so far, thus there is no persistent caching for aggregation.

-> Sould we make this persitent, too and set the channel flag? This way we could use for aggregation just like in trello.

 --> SH, no - just send it directly

onsite notification (Event)
-------------------

These notifications are displayed in the userbar with a counter for new messages (kind of like private messages). The top x messages are displayed via dropdown and there are links for message read and notification settings.

The onsite_message entity
-------------------------

The onsite_message is a straight entity shaped after the model module. The base fields are

* mid
* uid_target
* message_type
* message_data
* read
* created

Some other facts:

* onsite_messages have their own access logic and actions
* onsite_messages are marked as read, when the displaymode "full" has been called by the owner of the message!
*

