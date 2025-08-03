# Dhatree: Project File Structure

This document outlines the complete file and directory structure for the Dhatree project. It is designed based on a microservices architecture to ensure scalability, maintainability, and separation of concerns.

## 1. High-Level Project Directory

This is the root directory that will contain all the microservices, the frontend application, and shared configuration files.

```
dhatree-project/
├── api-gateway/
├── auth-service/
├── user-service/
├── pregnancy-tracking-service/
├── appointment-service/
├── notification-service/
├── ai-service/
├── frontend-app/
├── discovery-service/
├── config-server/
├── docker-compose.yml
└── README.md
```

---

## 2. Backend Microservice Structure (Spring Boot)

All backend microservices will follow a consistent structure. This example uses the `user-service`, but the same pattern applies to `auth-service`, `pregnancy-tracking-service`, etc.

### `auth-service`

```
auth-service/
├── src/
│   ├── main/
│   │   ├── java/
│   │   │   └── com/
│   │   │       └── dhatree/
│   │   │           └── authservice/
│   │   │               ├── controller/
│   │   │               │   ├── AuthController.java        // Handles email/password
│   │   │               │   ├── OAuth2Controller.java      // Handles "Sign in with Google" flow
│   │   │               │   └── PhoneAuthController.java   // Handles OTP send/verify flow
│   │   │               │
│   │   │               ├── service/
│   │   │               │   ├── AuthService.java
│   │   │               │   ├── OAuth2Service.java
│   │   │               │   └── OtpService.java            // Manages OTP logic
│   │   │               │
│   │   │               ├── client/
│   │   │               │   └── SmsServiceClient.java      // Client for SMS gateway (e.g., Twilio)
│   │   │               │
│   │   │               └── config/
│   │   │                   └── SecurityConfig.java        // Updated with OAuth2 client support
│   │   │
│   │   └── resources/
│   │       └── application.properties   // Add Google client-id/secret and SMS service keys
│   │
│   └── ...
│
├── pom.xml                                // Add dependencies for Spring Security OAuth2 Client
└── Dockerfile
```

### `user-service/`

```
user-service/
├── src/
│   ├── main/
│   │   ├── java/
│   │   │   └── com/
│   │   │       └── dhatree/
│   │   │           └── userservice/
│   │   │               ├── controller/      // REST API endpoints for different user types
│   │   │               │   ├── UserController.java
│   │   │               │   └── DoctorController.java
│   │   │               │
│   │   │               ├── model/           // Data models and entities
│   │   │               │   ├── User.java          // Base user with common fields (email, password)
│   │   │               │   ├── Role.java          // Enum for roles (ROLE_WOMAN, ROLE_HUSBAND, ROLE_DOCTOR)
│   │   │               │   ├── PregnantWomanProfile.java
│   │   │               │   ├── HusbandProfile.java
│   │   │               │   └── DoctorProfile.java // Includes specialization, credentials, etc.
│   │   │               │
│   │   │               ├── repository/      // Data Access Layer (Spring Data JPA)
│   │   │               │   ├── UserRepository.java
│   │   │               │   ├── DoctorProfileRepository.java
│   │   │               │   └── ...
│   │   │               │
│   │   │               ├── service/         // Business logic
│   │   │               │   ├── UserService.java   // Handles user registration, profile management
│   │   │               │   ├── DoctorService.java // Handles doctor-specific logic
|                       |   └──TwoFactorAuthService.java // Logic to generate secrets, QRcodesandverif
│   │   │               │
│   │   │               ├── dto/             // Data Transfer Objects for API responses
│   │   │               │   ├── UserDto.java
│   │   │               │   ├── DoctorDto.java
│   │   │               │   └── ...
│   │   │               │
│   │   │               └── config/          // Service-specific configurations (e.g., security)
│   │   │
│   │   └── resources/
│   │       ├── application.properties   // Main configuration file (ports, database, etc.)
│   │       └── static/                  // Static assets (if any)
│   │
│   └── test/                          // Unit and integration tests
│       └── java/
│           └── com/
│               └── dhatree/
│                   └── userservice/
│                       ├── controller/
│                       └── service/
│
├── pom.xml                                // Maven build and dependency management
└── Dockerfile                             // To containerize the service for deployment
```

### `ai-service/` (with RAG)

This service has a special structure to accommodate the Retrieval-Augmented Generation (RAG) pipeline.

```
ai-service/
├── src/
│   ├── main/
│   │   ├── java/
│   │   │   └── com/
│   │   │       └── dhatree/
│   │   │           └── aiservice/
│   │   │               ├── controller/
│   │   │               │   └── AiController.java       // Endpoint to receive user prompts
│   │   │               │
│   │   │               ├── service/
│   │   │               │   ├── RagService.java         // Orchestrates the RAG pipeline
│   │   │               │   └── KnowledgeBaseService.java // Manages vector store
│   │   │               │
│   │   │               ├── client/
│   │   │               │   ├── OpenAiClient.java       // Client to interact with OpenAI API
│   │   │               │   └── UserServiceApiClient.java // To fetch user-specific context
│   │   │               │
│   │   │               └── dto/
│   │   │                   ├── AiRequest.java
│   │   │                   └── AiResponse.java
│   │   │
│   │   └── resources/
│   │       ├── application.properties
│   │       └── knowledge_base/        // Curated, trusted documents
│   │           ├── nutrition.md
│   │           ├── third_trimester_symptoms.md
│   │           └── ...
│   │
│   └── test/
│
├── pom.xml
└── Dockerfile
```

---

## 3. Frontend Application Structure (React)

The frontend is structured to handle multiple user roles and dashboards, ensuring a clean and maintainable codebase.

### `frontend-app/`

```
frontend-app/
│
├── public/                     # Static assets that are not processed by Webpack
│   ├── index.html              # The main HTML template for the app
│   ├── favicon.ico             # The application's favicon
│   └── manifest.json           # PWA manifest
│
├── src/                        # The main source code for the application
│   │
│   ├── api/                    # Functions for making API calls to backend microservices
│   │   ├── apiClient.js          # Axios or Fetch instance with base URL and interceptors
│   │   ├── authApi.js            # API calls for authentication (login, register)
│   │   ├── userApi.js            # API calls for user profile management
│   │   ├── doctorApi.js          # API calls for searching/viewing doctor profiles
│   │   ├── appointmentApi.js     # API calls for managing appointments
│   │   ├── trackingApi.js        # API calls for pregnancy tracking data
│   │   └── aiApi.js              # API calls to the AI assistant service
│   │
│   ├── assets/                 # Static assets like images, fonts, icons
│   │   ├── images/
│   │   ├── icons/
│   │   └── fonts/
│   │
│   ├── components/             # Reusable UI components, organized by feature
│   │   ├── common/             # Highly reusable components
│   │   │   ├── Button.js
│   │   │   ├── Input.js
│   │   │   ├── Modal.js
│   │   │   ├── Spinner.js
│   │   │   └── Card.js
│   │   │
│   │   ├── layout/             # Components for the overall page structure
│   │   │   ├── Navbar.js
│   │   │   ├── Footer.js
│   │   │   ├── Sidebar.js
│   │   │   └── MainLayout.js
│   │   │
│   │   ├── auth/               # Components related to authentication
│   │   │   ├── LoginForm.js
│   │   │   ├── RegisterWomanForm.js
│   │   │   ├── RegisterHusbandForm.js
│   │   │   └── RegisterDoctorForm.js
│   │   │
│   │   ├── dashboard/          # Components specific to user dashboards
│   │   │   ├── HealthSummary.js
│   │   │   ├── WeeklyProgress.js
│   │   │   └── UpcomingAppointments.js
│   │   │
│   │   ├── diary/              # Components for the diary feature
│   │   │   ├── DiaryEntry.js
│   │   │   └── DiaryEditor.js
│   │   │
│   │   └── appointments/       # Components for appointment management
│   │       ├── AppointmentList.js
│   │       ├── AppointmentCard.js
│   │       └── BookAppointmentModal.js
│   │
│   ├── context/                # React Context for global state management
│   │   ├── AuthContext.js        # Manages user authentication state and roles
│   │   └── AppContext.js         # General app context (e.g., theme, language)
│   │
│   ├── hooks/                  # Custom React hooks for reusable logic
│   │   ├── useAuth.js            # Hook to access authentication context easily
│   │   ├── useApi.js             # Hook for handling API loading, error, and data states
│   │   └── useDebounce.js        # Hook for debouncing input
│   │
│   ├── pages/                  # Top-level components representing application pages
│   │   ├── LandingPage.js
│   │   ├── LoginPage.js
│   │   ├── RegisterPage.js       # A page to choose which user type to register as
│   │   ├── NotFoundPage.js
│   │   │
│   │   ├── woman/                # Pages specific to the pregnant woman role
│   │   │   ├── WomanDashboardPage.js
│   │   │   ├── DiaryPage.js
│   │   │   ├── MyHealthPage.js
│   │   │   └── FindDoctorPage.js
│   │   │
│   │   ├── husband/              # Pages specific to the husband role
│   │   │   └── HusbandDashboardPage.js
│   │   │
│   │   └── doctor/               # Pages specific to the doctor role
│   │       ├── DoctorDashboardPage.js
│   │       ├── MyPatientsPage.js
│   │       └── MyCalendarPage.js
│   │
│   ├── routes/                 # Routing logic
│   │   ├── AppRouter.js          # Defines all application routes
│   │   └── ProtectedRoute.js     # A component to protect routes based on user role
│   │
│   ├── styles/                 # Global styles and configuration
│   │   ├── global.css
│   │   └── tailwind.config.js    # If using Tailwind CSS
│   │
│   ├── utils/                  # Utility and helper functions
│   │   ├── dateUtils.js          # Functions for formatting dates
│   │   └── validators.js         # Functions for form validation
│   │
│   ├── App.js                  # Main application component, includes the router
│   └── index.js                # The entry point of the React application
│
├── .env                        # Environment variables (e.g., REACT_APP_API_GATEWAY_URL)
├── .gitignore                  # Specifies files to be ignored by Git
├── package.json                # Lists project dependencies and scripts
└── README.md                   # Instructions for setting up and running the frontend
```