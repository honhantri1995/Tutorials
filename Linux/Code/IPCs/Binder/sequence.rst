@startuml images/binder.png
skinparam NoteBackgroundColor #DDDDDD
skinparam NoteBorderColor #666666
skinparam ParticipantPadding 0
skinparam BoxPadding 40

TITLE Communicate between two processes using Binder
BOX Client Process #snow
	PARTICIPANT Client AS client #lightgreen
	PARTICIPANT IServiceManager AS sm
	PARTICIPANT BpHelloService AS bphs
	PARTICIPANT "BpBinder\n(Binder Proxy)" AS proxy
	PARTICIPANT IPCThreadState AS ts
END BOX
BOX Kernel
	PARTICIPANT "Binder Module" AS binder
END BOX
BOX Server Process #snow
	PARTICIPANT IPCThreadState AS ts2
	PARTICIPANT "BBinder\n(Binder Stub)" AS stub
	PARTICIPANT BnHelloService AS bnhs
	PARTICIPANT HelloService AS hs
	PARTICIPANT IServiceManager AS sm2
	PARTICIPANT Server AS server #lightgreen
END BOX

NOTE LEFT server #pink: [NOTE] Register a service to communicate with the client
server -> sm2++: addService(name)
	sm2 -> binder++
	RETURN
RETURN status
|||

NOTE LEFT server #pink: [NOTE] Server starts a thread pool and listen requests from client
server -> hs++: startThreadPool()
RETURN

server -> hs++: joinThreadPool()
	hs -> ts2++: joinThreadPool()
	RETURN
RETURN
	NOTE OVER ts2 #yellow: Wait (BLOCKING WAIT) for requests from client in an infinite loop
|||

NOTE RIGHT client #pink: [NOTE] Get the service registered by the server
client -> sm++: getService(name)
	sm -> binder++:
	RETURN
RETURN service
|||

NOTE RIGHT client #pink: [NOTE] Send a Hello message to the server
client -> bphs++: service->sayHello()
	NOTE OVER bphs: Serialize data into request parcel

	bphs -> proxy++: transact(requestParcel)
		proxy -> ts++: transact(requestParcel)
			ts -> binder++: talkWithDriver() \n<color #green>(via IOCtrl system call)
			RETURN

			NOTE OVER ts #yellow: Wait (BLOCKING WAIT) for response from server in an infinite loop
			|||
			|||

			LOOP
				ts2 -> ts2++: getAndExecuteCommand()
					NOTE RIGHT ts2 #pink: [NOTE] Get request parcel from Kernel Binder
					ts2 -> binder++: talkWithDriver() \n<color #green>(via IOCtrl system call)
					RETURN

					ALT parcel NOT found
						NOTE OVER ts2: Continue loop
					END

					NOTE RIGHT ts2 #lightblue: [NOTE] Wake up when having parcel and process it
					ts2 -> stub++: transact(requestParcel)
						stub -> bnhs++: onTransact()
							NOTE RIGHT bnhs #pink: [NOTE] Response a Hello message to the client

							NOTE OVER bnhs
								- De-serialize request parcel into request data
								- Create a response (based on the request data)
							END NOTE
						RETURN response data
					RETURN response data

					ts2 -> binder++: talkWithDriver() \n<color #green>(via IOCtrl system call)
					RETURN
				RETURN

			END
			|||
			|||

			LOOP
				NOTE LEFT binder #pink: [NOTE] Get response parcel from Kernel Binder
				ts -> binder++: talkWithDriver() \n<color #green>(via IOCtrl system call)
				RETURN

				ALT parcel NOT found
					NOTE OVER ts: Continue loop
				END

				NOTE RIGHT ts #lightblue: [NOTE] Wake up when having parcel and process it
				NOTE OVER ts: De-serialize parcel into response data

				RETURN response data
				RETURN response data

			END
	RETURN response data

@enduml





@startuml

package "lib/binder" {
	BBinder --|> IBinder
	IBinder --|> RefBase

	IServiceManager --|> IInterface

	class BBinder {
		+ status transact()
		- status onTransact()
	}

	interface IServiceManager {
		+ getService()
	}

	class "android::IPCThreadState" {
		+ joinThreadPool()
		+ talkWithDriver()
		+ getAndExecuteCommand()
		+ transact()
	}
}

package "Server and Client" {
	BpHelloService --|> "BpInterface<IHelloService>"

	HelloService --|> BnHelloService
	BnHelloService --|> "BnInterface<IHelloService>"

	IHelloService --|> IInterface

	BpServiceManager --|> "BpInterface<IServiceManager>"

	interface "BpInterface<IHelloService>" {
	}

	class BpHelloService {
		+ string sayhello()
	}

	interface IHelloService {
		+ sayhello()
	}

	interface "BnInterface<IHelloService>" {
		+ onTransact()
	}

	abstract BnHelloService {
	}

	class HelloService {
		+ publishAndJoinThreadPool()
		+ publish()  --> addService()
		+ sayhello()
		- joinThreadPool()
	}

	class BpServiceManager {
		+ addService()
	}

	class BnHelloService {
		+ onTransact()
	}
}

@enduml
