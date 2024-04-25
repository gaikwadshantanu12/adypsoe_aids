package Practical_3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface HotelServerInterface extends Remote{
    boolean bookRoom(String guestName, int roomNumber) throws RemoteException;
    boolean cancelBooking(int roomNumber) throws RemoteException;
}
