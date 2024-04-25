package Practical_3;

import java.rmi.Naming;
import java.util.Scanner;

public class HotelClient {
    public static void main(String[] args) {
        try {
            HotelServerInterface serverInterface = (HotelServerInterface) Naming.lookup("rmi://localhost/HotelServer");
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("Choose an option :");
                System.out.println("1. Book a room");
                System.out.println("2. Cancel Booking");
                System.out.println("3. Exit");
                int choice = scanner.nextInt();

                switch (choice) {
                    case 1:
                        System.out.println("Enter guest name : ");
                        String guestName = scanner.next();
                        System.out.println("Enter room number : ");
                        int roomNumber = scanner.nextInt();
                        boolean booked = serverInterface.bookRoom(guestName, roomNumber);
                        if (booked) {
                            System.out.println("Room booked successfully !");
                        } else {
                            System.out.println("Room already booked !");
                        }
                        break;

                    case 2:
                        System.out.println("Enter room number to cancel booking : ");
                        int roomToCancel = scanner.nextInt();
                        boolean cancelled = serverInterface.cancelBooking(roomToCancel);
                        if (cancelled) {
                            System.out.println("Booking canceled successfully !");
                        } else {
                            System.out.println("No booking found for this room !");
                        }
                        break;

                    case 3:
                    System.out.println("Exiting...");
                    System.exit(0);
                
                    default:
                        System.out.println("Invalid Option. Please choose again.");
                        break;
                }
            }

        } catch (Exception e) {
            System.err.println("Client Exception : " + e.toString());
            e.printStackTrace();
        }
    }
}
