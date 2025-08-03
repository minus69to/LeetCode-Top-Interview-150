Dhatree API Documentation (Version 1)

Welcome to the Dhatree API documentation. This document provides a complete specification for all RESTful endpoints.

Base URL: https://api.dhatree.com/api/v1/

Authentication: Most endpoints require a Bearer Token in the Authorization header.

1. Authentication Service (/api/v1/auth)

Handles user registration, multi-factor login, and token management.

1.1 Register New User

    Endpoint: POST /api/v1/auth/register

    Request Body:
    JSON

{
  "email": "user@example.com",
  "password": "strongpassword123",
  "fullName": "Jane Doe",
  "role": "ROLE_WOMAN"
}

Responses:

    201 Created:
    JSON

{
  "userId": "c7a8f3b2-9d6e-4b1a-8c3f-0e1d2a3b4c5d",
  "message": "User registered successfully."
}

400 Bad Request (e.g., validation error):
JSON

{
  "timestamp": "2025-07-16T09:59:00Z",
  "status": 400,
  "error": "Bad Request",
  "message": "Password must be at least 8 characters long.",
  "path": "/api/v1/auth/register"
}

409 Conflict (e.g., email already exists):
JSON

        {
          "timestamp": "2025-07-16T09:59:00Z",
          "status": 409,
          "error": "Conflict",
          "message": "A user with this email already exists.",
          "path": "/api/v1/auth/register"
        }

1.2 Login with Email/Password (Step 1)

    Endpoint: POST /api/v1/auth/login

    Request Body:
    JSON

{
  "email": "user@example.com",
  "password": "strongpassword123"
}

Responses:

    200 OK (2FA is NOT enabled):
    JSON

{
  "isTwoFactorEnabled": false,
  "accessToken": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c",
  "refreshToken": "a_longer_secure_refresh_token"
}

200 OK (2FA IS enabled):
JSON

{
  "isTwoFactorEnabled": true,
  "message": "Please verify your 2FA code.",
  "mfaToken": "a_temporary_mfa_token_valid_for_5_minutes"
}

401 Unauthorized:
JSON

        {
          "timestamp": "2025-07-16T09:59:00Z",
          "status": 401,
          "error": "Unauthorized",
          "message": "Invalid email or password.",
          "path": "/api/v1/auth/login"
        }

1.3 Verify 2FA Code (Step 2)

    Endpoint: POST /api/v1/auth/verify-2fa

    Request Body:
    JSON

{
  "mfaToken": "a_temporary_mfa_token_valid_for_5_minutes",
  "code": "123456"
}

Responses:

    200 OK:
    JSON

{
  "accessToken": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiaWF0IjoxNTE2MjM5MDIyfQ.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c",
  "refreshToken": "a_longer_secure_refresh_token"
}

401 Unauthorized:
JSON

        {
          "timestamp": "2025-07-16T09:59:00Z",
          "status": 401,
          "error": "Unauthorized",
          "message": "Invalid 2FA code or token.",
          "path": "/api/v1/auth/verify-2fa"
        }

2. User Service (/api/v1/users)

2.1 Get Current User's Profile

    Endpoint: GET /api/v1/users/me

    Authorization: Bearer <accessToken>

    Responses:

        200 OK:
        JSON

{
  "userId": "c7a8f3b2-9d6e-4b1a-8c3f-0e1d2a3b4c5d",
  "email": "user@example.com",
  "fullName": "Jane Doe",
  "role": "ROLE_WOMAN",
  "isTwoFactorEnabled": true,
  "profile": {
    "lastMenstruationDate": "2025-01-15",
    "linkedHusbandId": "e6a1b2c3-d4e5-f6a7-b8c9-d0e1f2a3b4c5"
  }
}

401 Unauthorized:
JSON

        { "message": "Authentication token is missing or invalid." }

2.2 Manage 2FA

    Enable 2FA: POST /api/v1/users/me/2fa/enable

    Authorization: Bearer <accessToken>

    Responses:

        200 OK:
        JSON

    {
      "secret": "JBSWY3DPEHPK3PXP",
      "qrCodeUrl": "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAQAAAC1HAwCAAAAC0lEQVR42mNkYAAAAAYAAjCB0C8AAAAASUVORK5CYII="
    }

Disable 2FA: POST /api/v1/users/me/2fa/disable

Authorization: Bearer <accessToken>

Responses:

    200 OK:
    JSON

        {
          "message": "Two-factor authentication has been disabled."
        }

3. Diary Service (/api/v1/diary)

3.1 Create Diary Entry

    Endpoint: POST /api/v1/diary/entries

    Authorization: Bearer <accessToken>

    Request Body:
    JSON

{
  "title": "First Ultrasound",
  "content": "Saw the baby for the first time today! So exciting. The doctor said everything looks perfect.",
  "mood": "EXCITED",
  "entryDate": "2025-03-20"
}

Responses:

    201 Created:
    JSON

        {
          "entryId": "diary-uuid-001",
          "title": "First Ultrasound",
          "content": "Saw the baby for the first time today! So exciting. The doctor said everything looks perfect.",
          "mood": "EXCITED",
          "entryDate": "2025-03-20",
          "createdAt": "2025-07-16T10:15:00Z"
        }

3.2 Get Diary Entries

    Endpoint: GET /api/v1/diary/entries

    Authorization: Bearer <accessToken>

    Responses:

        200 OK:
        JSON

        [
          {
            "entryId": "diary-uuid-001",
            "title": "First Ultrasound",
            "mood": "EXCITED",
            "entryDate": "2025-03-20",
            "createdAt": "2025-07-16T10:15:00Z"
          }
        ]

4. Consultation Service (/api/v1/consultations)

4.1 Book an Appointment

    Endpoint: POST /api/v1/consultations/appointments

    Authorization: Bearer <accessToken>

    Request Body:
    JSON

{
  "doctorId": "doctor-uuid-789",
  "appointmentTime": "2025-08-01T14:00:00Z",
  "notes": "General check-up and some questions about diet."
}

Responses:

    201 Created:
    JSON

{
  "appointmentId": "appt-uuid-101",
  "patientId": "c7a8f3b2-9d6e-4b1a-8c3f-0e1d2a3b4c5d",
  "doctorId": "doctor-uuid-789",
  "appointmentTime": "2025-08-01T14:00:00Z",
  "status": "CONFIRMED",
  "notes": "General check-up and some questions about diet."
}

404 Not Found (Doctor not found):
JSON

        { "message": "Doctor with the specified ID was not found." }

4.2 Initiate Video Call

    Endpoint: POST /api/v1/consultations/chats/{appointmentId}/initiate-video

    Authorization: Bearer <accessToken>

    Responses:

        200 OK:
        JSON

{
  "videoRoomId": "room-xyz-123",
  "videoAccessToken": "a_token_for_the_video_service_like_twilio"
}

403 Forbidden:
JSON

        { "message": "You are not a participant in this appointment." }

5. Places Service (/api/v1/places)

5.1 Find Nearby Services

    Endpoint: GET /api/v1/places/nearby?lat=23.8103&lon=90.4125&type=hospital&radius=5000

    Authorization: Bearer <accessToken>

    Responses:

        200 OK:
        JSON

        [
          {
            "placeId": "google-place-id-1",
            "name": "Dhaka General Hospital",
            "address": "123 Health St, Dhaka, Bangladesh",
            "location": {
              "lat": 23.8110,
              "lon": 90.4130
            },
            "rating": 4.5,
            "phoneNumber": "+880-2-1234567"
          }
        ]

6. Community Service (/api/v1/community)

6.1 Get Community Posts

    Endpoint: GET /api/v1/community/posts

    Authorization: Bearer <accessToken>

    Responses:

        200 OK:
        JSON

        {
          "posts": [
            {
              "postId": "post-uuid-abc",
              "authorId": "user-uuid-xyz",
              "authorName": "Sarah K.",
              "title": "Any advice for morning sickness?",
              "content": "I'm in my first trimester and looking for tips...",
              "commentCount": 5,
              "createdAt": "2025-07-15T14:30:00Z"
            }
          ],
          "page": 1,
          "totalPages": 10
        }

6.2 Add a Comment to a Post

    Endpoint: POST /api/v1/community/posts/{postId}/comments

    Authorization: Bearer <accessToken>

    Request Body:
    JSON

{
  "content": "I found that eating small, frequent meals and sipping ginger tea really helped me."
}

Responses:

    201 Created:
    JSON

{
  "commentId": "comment-uuid-123",
  "postId": "post-uuid-abc",
  "authorId": "user-uuid-456",
  "authorName": "Jane Doe",
  "content": "I found that eating small, frequent meals and sipping ginger tea really helped me.",
  "createdAt": "2025-07-16T11:00:00Z"
}

404 Not Found (Post not found):
JSON

        { "message": "The specified post was not found." }

7. AI Service (/api/v1/ai)

7.1 Chat with the AI Assistant

    Endpoint: POST /api/v1/ai/chat

    Authorization: Bearer <accessToken>

    Request Body:
    JSON

{
  "prompt": "What are some safe exercises for the second trimester?"
}

Responses:

    200 OK:
    JSON

{
  "response": "That's a great question! In the second trimester, exercises like swimming, prenatal yoga, and walking are generally considered safe and beneficial. They can help with circulation and strength. It's always a good idea to listen to your body and consult with your doctor before starting a new routine. Would you like me to suggest some specific stretches?",
  "sources": [
    {
      "document": "safe_exercise_guidelines.md",
      "confidence": 0.95
    }
  ]
}

503 Service Unavailable:
JSON

        {
          "message": "The AI assistant is currently unavailable. Please try again later."
        }

8. Real-time Notification Service

    Protocol: WebSocket

    Endpoint: wss://api.dhatree.com/ws/notifications

    Description: This is not a REST API. A client establishes a persistent WebSocket connection after login to receive real-time events.

    Example Event (Server -> Client):
    JSON

{
  "eventType": "APPOINTMENT_REMINDER",
  "payload": {
    "appointmentId": "appt-uuid-101",
    "message": "Reminder: You have an appointment with Dr. Smith in 1 hour."
  }
}
