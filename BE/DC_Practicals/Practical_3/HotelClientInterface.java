package Practical_3;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface HotelClientInterface extends Remote {
    void displayMessage(String message) throws RemoteException;
}
