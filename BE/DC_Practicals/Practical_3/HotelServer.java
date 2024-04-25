package Practical_3;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.HashMap;
import java.util.Map;

public class HotelServer  extends UnicastRemoteObject implements HotelServerInterface {
    private Map<Integer, String> roomBookings;

    public HotelServer() throws RemoteException {
        roomBookings = new HashMap<>();
    }

    @Override
    public synchronized boolean bookRoom(String guestName, int roomNumber) throws RemoteException {
        if(roomBookings.containsKey(roomNumber)) {
            return false;
        } else {
            roomBookings.put(roomNumber, guestName);
            return true;
        }
    }

    @Override
    public synchronized boolean cancelBooking(int roomNumber) throws RemoteException {
        if(roomBookings.containsKey(roomNumber)) {
            roomBookings.remove(roomNumber);
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        try {
            HotelServer server = new HotelServer();
            LocateRegistry.createRegistry(1098);
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind("HotelServer", server);
            System.out.println("Hotel server is ready...");
        } catch (Exception e) {
            System.err.println("Server exception : " + e.toString());
            e.printStackTrace();
        }
    }
}
